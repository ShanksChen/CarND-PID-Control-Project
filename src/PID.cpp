#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) 
{
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	this->sum_cte = 0;
	this->previous_cte = 0;
  this->first_time = true;
}

void PID::UpdateError(double cte) {
  // first time update the error
	if (this->first_time) {
		this->previous_cte = cte;
		this->first_time = false;
	}

	this->sum_cte += cte;
	double diffCte = cte - this->previous_cte;
	this->previous_cte = cte;

	this->p_error = cte;
	this->d_error = diffCte;
	this->i_error = this->sum_cte;
}

double PID::TotalError() {
	return -this->Kp * this->p_error - this->Ki * this->i_error - this->Kd * this->d_error;
}