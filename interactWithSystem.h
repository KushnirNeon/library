#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>

#ifndef INTERACTWITHSYSTEM_H
#define INTERACTWITHSYSTEM_H

#include "book.h"
#include "magazine.h"
#include "library.h"

bool interactWithSystem (std::vector <Book> books, std::vector <Magazine> magazines);

#endif
