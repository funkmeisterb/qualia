/*
 * DataSetTrainer.cpp
 *
 * This file is part of Qualia https://github.com/sofian/qualia
 *
 * Based on code from Torch 3.1
 * (c) 2013 Sofian Audry -- info(@)sofianaudry(.)com
 * (c) 2003--2004 Ronan Collobert (collober@idiap.ch)
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

#include "DataSetTrainer.h"

DataSetTrainer::DataSetTrainer(Function* function_) : Trainer(function_), nEpisodes(0) {
}

DataSetTrainer::~DataSetTrainer() {
}

void DataSetTrainer::init() {
  function->init();
  nEpisodes = 0;
}

void DataSetTrainer::train(DataSet* data, int maxEpisodes) {
  init();
  data->init();
  MESSAGE("Training on %d examples.", data->nExamples);
  while (!stop() &&
         (maxEpisodes > 0 && nEpisodes < maxEpisodes)) {
    trainEpisode(data);
  }
}

void DataSetTrainer::trainEpisode(DataSet* data) {
  ASSERT_WARNING(data->nExamples >= 0);
  MESSAGE("Training episode # %d.", nEpisodes);
  _doTrainEpisode(data);
  nEpisodes++;
}


