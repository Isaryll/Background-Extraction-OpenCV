/*
 * Gaussian.cpp
 *
 *  Created on: 22 de out de 2018
 *      Author: isa
 */

#include <Gaussian.h>

Gaussian::Gaussian(const Vec3b& media, const double& dev, const double& weight): media(media), weight(weight) {
	setDev(dev);
}

void Gaussian::setDev(const double& d) {
	dev = d;
}

double Gaussian::prob(const cv::Vec3b& current) const {
	Vec3b temp = Vec3b(current - media);
	double num = exp(-0.5 * (temp.val[0] * temp.val[0] + temp.val[1] * temp.val[1] + temp.val[2] * temp.val[2]) * dev);
	double den = PART * pow(dev, 0.5);
	return num/den;
}
