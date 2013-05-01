// File: common.hh
// Date: Wed May 01 22:52:37 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#pragma once

#include <cmath>
#include <vector>
#include <iostream>
#include <utility>
#include <limits>

#include "debugutils.hh"

extern bool PANO;
extern bool CIRCLE;

typedef double real_t;
const real_t EPS = 1e-6;
const real_t SEPS = std::numeric_limits<real_t>::epsilon();
inline real_t sqr(real_t x) { return x * x; }

const int NUM_OCTAVE = 4;		// XXX 4?
const int NUM_SCALE = 6;
const real_t SCALE_FACTOR = sqrt(2);

const real_t GAUSS_SIGMA = SCALE_FACTOR;
const int GAUSS_WINDOW_FACTOR = 6;		// before: 4

const real_t JUDGE_EXTREMA_DIFF_THRES = +5e-3;
const real_t CONTRAST_THRES = 6e-2;		// lowe: 3e-2
const real_t PRE_COLOR_THRES = 5e-2;
const real_t EDGE_RATIO = 6;		// lowe: 10

const int CALC_OFFSET_DEPTH = 4;
const real_t OFFSET_THRES = 0.3;

const real_t ORI_WINDOW_FACTOR = 1.5;		// lowe
const real_t ORI_RADIUS = 3 * ORI_WINDOW_FACTOR;

const int ORT_HIST_BIN_NUM = 36;		// lowe
const int ORT_HIST_SMOOTH_COUNT = 2;
const real_t ORT_HIST_PEAK_RATIO = 0.8;		// lowe : 0.8

const int DESC_HIST_WIDTH = 4;
const int DESC_HIST_REAL_WIDTH = 3;
const int DESC_HIST_BIN_NUM = 8;
const real_t DESC_NORM_THRESH = 0.2;		// lowe
const int DESC_INT_FACTOR = 512;
const int DESC_LEN = 128;

const real_t MATCH_REJECT_NEXT_RATIO = 0.8; // lowe : 0.8
const int MATCH_MIN_SIZE = 0;
const real_t CONNECTED_THRES = 0.07;		// matched feature percentage higher than this

const bool USE_HOMO = !PANO;
const int HOMO_FREEDOM = 8;
const int AFFINE_FREEDOM = 6;
const int RANSAC_ITERATIONS = 30;
const real_t RANSAC_INLIER_THRES = 2;

const real_t SLOPE_PLAIN = 6e-3;

const real_t FOCAL = 300;

#define between(a, b, c) ((a >= b) && (a <= c - 1))
#define REP(x, y) for (int x = 0; x < (y); x ++)
#define REPL(x, y, z) for (int x = y; x < (z); x ++)
#define REPD(x, y, z) for (int x = y; x >= (z); x --)

#define toCoor(a) Coor((a).x, (a).y)

#define P(a) std::cout << (a) << std::endl
#define PP(s, a) std::cout << s << " " << (a) << std::endl

template <typename T>
inline void free_2d(T** ptr, int w) {
	if (ptr != nullptr)
		for (int i = 0; i < w; i ++)
			delete[] ptr[i];
	delete[] ptr;
}

template<typename T>
bool update_min(T &dest, const T &val) {
	if (val < dest) {
		dest = val; return true;
	}
	return false;
}

template<typename T>
bool update_max(T &dest, const T &val) {
	if (dest < val) {
		dest = val; return true;
	}
	return false;
}

