#ifndef THRUST_ATTACHMENT_H__
#define THRUST_ATTACHMENT_H__

#include "quat.h"

struct thrust_attachment_point {
	int nports;
	struct _port {
		float scale;
		union vec3 pos;
	} port[5];
};

struct thrust_attachment_point *read_thrust_attachments(char *filename);

#endif
