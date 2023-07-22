#include <signal.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/uinput.h>
#include <stdlib.h>

/*
* GPLv3 - See licence
* this C program is heavily based on altf1.c
* https://github.com/puppylinux-woof-CE/woof-CE/blob/testing/woof-code/rootfs-petbuilds/labwc/altf1d.c
*/

int main(int argc, char *argv[])
{
	sigset_t set;
	struct uinput_setup setup = {.name = "ctrllrd"};
	struct input_event event = {0};
	int uinput, sig, ret = EXIT_FAILURE;

	if ((sigemptyset(&set) < 0) ||
	    (sigaddset(&set, SIGUSR1) < 0) ||
	    (sigaddset(&set, SIGUSR2) < 0) ||
	    (sigaddset(&set, SIGTERM) < 0) ||
	    (sigprocmask(SIG_BLOCK, &set, NULL) < 0))
		return EXIT_FAILURE;

	uinput = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
	if (uinput < 0)
		return EXIT_FAILURE;
	
	if ((ioctl(uinput, UI_SET_EVBIT, EV_KEY) < 0) ||
	    (ioctl(uinput, UI_SET_KEYBIT, KEY_LEFTCTRL) < 0) ||
	    (ioctl(uinput, UI_SET_KEYBIT, KEY_L) < 0) ||
	    (ioctl(uinput, UI_SET_KEYBIT, KEY_R) < 0) ||
	    (ioctl(uinput, UI_DEV_SETUP, &setup) < 0) ||
	    (ioctl(uinput, UI_DEV_CREATE) < 0)) {
		close(uinput);
		return EXIT_FAILURE;
	}

	while (sigwait(&set, &sig) == 0) {
		unsigned short keylr;
		
		if (sig == SIGTERM) {
			ret = EXIT_SUCCESS;
			break;
		}
		
		if (sig == SIGUSR1) {
			keylr = KEY_L;
		}
		else if (sig == SIGUSR2) {
			keylr = KEY_R;
		}
		else {
			ret = EXIT_FAILURE;
			break;
		}

		event.type = EV_KEY;
		event.code = KEY_LEFTCTRL;
		event.value = 1;

		if (write(uinput, &event, sizeof(event)) != sizeof(event))
			break;

		event.code = keylr;

		if (write(uinput, &event, sizeof(event)) != sizeof(event))
			break;

		event.type = EV_SYN;
		event.code = SYN_REPORT;
		event.value = 0;

		if (write(uinput, &event, sizeof(event)) != sizeof(event))
			break;

		event.type = EV_KEY;
		event.code = KEY_LEFTCTRL;
		event.value = 0;

		if (write(uinput, &event, sizeof(event)) != sizeof(event))
			break;

		event.code = keylr;

		if (write(uinput, &event, sizeof(event)) != sizeof(event))
			break;
	}

	ioctl(uinput, UI_DEV_DESTROY);
	close(uinput);

	return ret;
}
