#ifndef REMOTE_H
#define REMOTE_H

class remote
{
	virtual void turn_on() = 0;

	virtual void turn_off() = 0;

	virtual void change_channel() = 0;

	virtual void set_channel(int n) = 0;

	virtual void increase_volume() = 0;

	virtual void decrease_volume() = 0;

	virtual void previous_channel() = 0;

	virtual void next_channel() = 0;

};

#endif