#include "pch.h"
#include "bezier.h"
#include "utils.h"
#include "iostream"




Bezier CalculateBezier(Point2f pointA, Point2f pointD, Point2f pointB, Point2f pointC)
{
	std::vector<Point2f> calculatedBezier = std::vector<Point2f>(BEZIER_STEPS_AMOUNT);
	Point2f AB_Lerp{};
	Point2f BC_Lerp{};
	Point2f CD_Lerp{};
	Point2f AB_BC_Lerp{};
	Point2f BC_CD_Lerp{};
	Point2f curvePoint{};

	for (int i{}; i < BEZIER_STEPS_AMOUNT; i++)
	{
		float multiplier{ (1.f/BEZIER_STEPS_AMOUNT)*i };
		//the lerps for the first 3 lines
		AB_Lerp.x = Lerp(pointA.x, pointB.x, multiplier);
		AB_Lerp.y = Lerp(pointA.y, pointB.y, multiplier);
		BC_Lerp.x = Lerp(pointB.x, pointC.x, multiplier);
		BC_Lerp.y = Lerp(pointB.y, pointC.y, multiplier);
		CD_Lerp.x = Lerp(pointC.x, pointD.x, multiplier);
		CD_Lerp.y = Lerp(pointC.y, pointD.y, multiplier);
		//the lerps for the 2 created lines
		AB_BC_Lerp.x = Lerp(AB_Lerp.x, BC_Lerp.x, multiplier);
		AB_BC_Lerp.y = Lerp(AB_Lerp.y, BC_Lerp.y, multiplier);
		BC_CD_Lerp.x = Lerp(BC_Lerp.x, CD_Lerp.x, multiplier);
		BC_CD_Lerp.y = Lerp(BC_Lerp.y, CD_Lerp.y, multiplier);
		//the point of the curve
		curvePoint.x = Lerp(AB_BC_Lerp.x, BC_CD_Lerp.x, multiplier);
		curvePoint.y = Lerp(AB_BC_Lerp.y, BC_CD_Lerp.y, multiplier);
		calculatedBezier[i] = curvePoint;
	}
	Bezier solution{};
	solution.curvePoints = calculatedBezier;
	return solution;
}

float Lerp(float a, float b, float multiplier)
{

	return (a + (b - a) * multiplier);
}

void DrawBezier(Bezier bezier,float lineWidth )
{
	for (int i{}; i < BEZIER_STEPS_AMOUNT-1; i++)
	{
		utils::DrawLine(bezier.curvePoints[i], bezier.curvePoints[i + 1], lineWidth);
	}
}
