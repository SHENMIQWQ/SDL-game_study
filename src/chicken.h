#ifndef _CHICKEN_H_
#define _CHICKEN_H_

#include "camera.h"
#include "vector2.h"
#include "animation.h"

#include <SDL_mixer.h>

extern Atlas atlas_explosion;

extern Mix_Chunk* sound_explosion;

class Chicken
{
public:
	Chicken()
	{
		animation_run.set_loop(true);
		animation_run.set_interval(0.1f);

		animation_explosion.set_loop(false);
		animation_explosion.set_interval(0.08f);
		animation_explosion.add_frame(&atlas_explosion);
		animation_explosion.set_on_finished([&]()
			{
				is_valid = false;
			});

		position.x = 40.0f + (rand() % 1200);
		position.y = -50;
	}

	~Chicken() = default;

	const Vector2& get_position() const
	{
		return position;
	}

	void on_update(float delta)
	{
		if (is_alive)
			position.y += speed_run * delta;

		animation_current = (is_alive ? &animation_run : &animation_explosion);
		animation_current->set_position(position);
		animation_current->on_update(delta);
	}

	void on_render(const Camera& camera) const
	{
		animation_current->on_render(camera);
	}

	void on_hurt()
	{
		is_alive = false;

		Mix_PlayChannel(-1, sound_explosion, 0);
	}

	void make_invalid()
	{
		is_valid = false;
	}

	bool check_alive() const
	{
		return is_alive;
	}

	bool can_remove() const
	{
		return !is_valid;
	}

protected:
	float speed_run = 10.0f;
	Animation animation_run;

private:
	Vector2 position;
	Animation animation_explosion;
	Animation* animation_current = nullptr;

	bool is_alive = true;
	bool is_valid = true;
	
};

#endif // !_CHICKEN_H_
