// This file is imported to use "pQueueLL.h"
// Includes file with different types (int, char, float, double), but other primitive types can be added easily like so:
/*
#define TYPE newType
#define GI(name) name ## newType
#include "pQueueLL.h"
*/

// GI stands for Generic Indentifier, it concatenates name with the TYPE, for example GI(display_) becomes display_int when the TYPE is int

#define TYPE int
#define GI(name) name ## int
#include "pQueueLL.h"

#define TYPE char
#define GI(name) name ## char
#include "pQueueLL.h"

#define TYPE float
#define GI(name) name ## float
#include "pQueueLL.h"

#define TYPE double
#define GI(name) name ## double
#include "pQueueLL.h"


