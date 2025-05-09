#include <stdbool.h>
#include <oak_util/types.h>

#define SHRUB_API extern "C"

SHRUB_API iptr add(iptr a, iptr b) {
	return a*a + b;
}
