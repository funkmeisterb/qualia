/*
 * QFunction.cpp
 *
 * (c) 2013 Sofian Audry -- info(@)sofianaudry(.)com
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

#include "QFunction.h"

QFunction::QFunction(GradientFunction* function_) : function(function_) {
  input = (real*) Alloc::malloc( function->nInput() * sizeof(real) );
  weights = function->weights;
  dWeights = function->dWeights;
}

QFunction::~QFunction() {
  Alloc::free(input);
}

real QFunction::getValue(const Observation* observation, const Action* action) {

  // Set input.
  int k = 0;
  for (int i = 0; i < (int)observation->dim; i++, k++)
    input[k] = observation->observations[i];

  // Actions are remapped to [0,1].
  for (int i = 0; i < (int)action->dim(); i++, k++)
    input[k] = mapReal((real)action->actions[i], 0, action->nActions(i) - 1, -1.0f, 1.0f);

  // Propagate.
  real output;
  function->setInput(input);
  function->propagate();
  function->getOutput(&output);
  return output;
}

void QFunction::getMaxAction(Action* dst, const Observation* observation, real *maxQ) {
  ASSERT_ERROR(dst);

  dst->reset();
  action_t actionMax = dst->conflated();
  real outMax        = getValue(observation, dst);

  while (dst->hasNext()) {
    dst->next();
    real out = getValue(observation, dst);
    if (out > outMax) {
      actionMax = dst->conflated();
      outMax    = out;
    }
  }
  dst->setConflated(actionMax);

  if (maxQ) // optional
    *maxQ = outMax;
}
