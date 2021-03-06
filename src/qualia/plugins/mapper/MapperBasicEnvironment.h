/*
 * MapperBasicEnvironment.h
 *
 * (c) 2012 Sofian Audry -- info(@)sofianaudry(.)com
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

#ifndef MAPPERBASICENVIRONMENT_H_
#define MAPPERBASICENVIRONMENT_H_

#include "MapperEnvironment.h"
#include <qualia/core/Observation.h>

class MapperBasicEnvironment : public MapperEnvironment {
public:
  Observation currentObservation;
  int actionDim;

  MapperBasicEnvironment(int observationDim, int actionDim, MapperConnector* connector);
  virtual ~MapperBasicEnvironment();

  virtual void addSignals();
  virtual void writeOutputs(const Action* action);
  virtual Observation* readInputs();
};

#endif /* MAPPERBASICENVIRONMENT_H_ */
