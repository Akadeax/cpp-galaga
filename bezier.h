#pragma once
constexpr int BEZIER_STEPS_AMOUNT{ 101 };
struct Bezier
{
	std::vector<Point2f> curvePoints = std::vector<Point2f>(BEZIER_STEPS_AMOUNT);
};

Bezier CalculateBezier(Point2f startPoint,Point2f endPoint,Point2f pullPoint1, Point2f pullPoint2);
float Lerp(float a, float b, float multiplier);
Point2f Lerp(Point2f a, Point2f b, float multiplier);
void DrawBezier(Bezier bezier, float lineWidth);
void FillBezier(Bezier bezier);

