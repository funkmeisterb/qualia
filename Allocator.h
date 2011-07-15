/*
 * Allocator.h
 *
 * (c) 2011 Sofian Audry -- info(@)sofianaudry(.)com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_

#include <stddef.h>


class Allocator {
public:
  virtual ~Allocator() {}

  virtual void* malloc(size_t size);
  virtual void free(void* ptr);
};

class Alloc {
  static Allocator* instance;

public:
  static void* malloc(size_t size);
  static void free(void* ptr);
  static void init(Allocator* alloc);
};

#endif /* ALLOCATOR_H_ */