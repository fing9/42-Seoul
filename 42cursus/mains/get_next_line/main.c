#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int fd;
	fd = open("./text", O_RDONLY, 0644);
	
	char *str;
	while (1) {
		str = get_next_line(fd);
		if (str == NULL)
			break;
		printf("%s", str);
		free(str);
	}
}