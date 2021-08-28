#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

// Will be using double cause low end specs

class vec3 {
    public:
	vec3() : e{0,0,0} {}		//creating vec3 constructor for a vector e...
	vec3(double e0, double e1, double e2) : e{e0, e1, e2} {} //initializing vec3 constructor telling it to take doubleed vector parameters from vector e

	double x() const { return e[0]; } //for x return position 0 e vector
	double y() const { return e[1]; } //for y return position 1 e vector
	double z() const { return e[2]; } //for z return position 2 e vector

//now they correspond to a classical 3D system.

	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); } //defining when using operator- so the negative value in each x y z to be returned

	double operator[](int i) const { return e[i]; } //when using operator[] define it as array with position i.

	double& operator[](int i) { return e[i]; } //when using operator[] with memory reference, return array value of position i.

	vec3& operator+=(const vec3 &v) { //when using operator+= on memory referenced vector v
	    e[0] += v.e[0];
	    e[1] += v.e[1];
	    e[2] += v.e[2];
	    return *this;
	}

	vec3& operator*=(const double t) {
	    e[0] *= t;
	    e[1] *= t;
	    e[2] *= t;
	    return *this;
	}

	vec3& operator/=(const double t) {
	    return *this *= 1/t;
	}

	double length() const {		//calculating vector length
	   return sqrt(length_squared());
	}

	double length_squared() const {	//vector length squared
	   return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
	}

    public:
	double e[3];
};

// Type aliases for vec3
using point3 = vec3;	//3D point
using color = vec3;	//RGB color


// vec3 Utility Functions

//making operator<< outputting vector correctly from memory reference
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) { 
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

//just simple vector addition on vectors in memory reference
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

//vector substraction
inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

//vector multiplication
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

//vector v multiplied by double t value
inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

//dotproduct
inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
	 + u.e[1] * v.e[1]
	 + u.e[2] * v.e[2];
}

//crossproduct
inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
		u.e[2] * v.e[0] - u.e[0] * v.e[2],
		u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif
