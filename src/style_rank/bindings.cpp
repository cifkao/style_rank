#include "utils.hpp"
#include "parse.hpp"
#include "features.hpp"
#include "feature_map.hpp"

#include <tuple>
#include <vector>
#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
namespace py = pybind11;
using namespace std;

vector<string> get_feature_names() {
  return extract_keys<string,unique_ptr<DISCRETE_DIST>(*)(Piece*)>(m);
}

tuple<VECTOR_MAP,VECTOR_MAP,vector<int>> get_features_internal(vector<string> &paths, vector<string> &feature_names, int upper_bound, int resolution, bool include_offsets) {
  if (feature_names.size() == 0) {
    feature_names = get_feature_names();
  }
  Collector c;
  vector<int> indices;
  for (int i=0; i<paths.size(); i++) {
    Piece *p = new Piece(paths[i], resolution, include_offsets);
    if ((p) && (p->chords.size() > 10)) {
      for (const auto &name : feature_names) {
        c.add(name, m[name](p));
      }
      indices.push_back(i);
    }
  }
  return tuple_cat(c.getData(upper_bound), tie(indices));
}

PYBIND11_MODULE(_style_rank,m) {
  m.def("get_features_internal", &get_features_internal);
  m.def("get_feature_names", &get_feature_names);
}