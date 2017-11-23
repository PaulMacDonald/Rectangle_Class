/*
-----------
RECTANGLE2D
-----------
- x : double
- y : double
- width : double
- height : double
--------------------------------------------------------------------------
+ Rectangle2D()
+ Rectangle2D(theX:double, theY:double, theWidth:double, theHeight:double)
+ setX()
+ setY()
+ setWidth()
+ setHeight()
+ getX(): double
+ getY(): double
+ getWidth(): double
+ getHeight(): double
+ getArea(): double
+ getPerimeter(): double
+ getRightSide(): double
+ getLeftSide(): double
+ getTop(): double
+ getBottom(): double
+ contains(theX: double, theY: double): bool
+ contains(r: Rectangle2D): bool
+ overlaps(r: Rectangle2D): bool
--------------------------------------------------------------------------
*/

#ifndef RECTANGLE2D_H_
#define RECTANGLE2D_H_

class Rectangle2D
{
private:
	double x; // x-coordinate of center of rectangle
	double y; // y-coordinate of center of rectangle
	double width;
	double height;

public:
	/*CONSTRUCTORS*/

	// default constructor
	Rectangle2D()
	{
		x = 0;
		y = 0;
		width = 1;
		height = 1;
	}

	// specific rectangle constructor
	Rectangle2D(double theX, double theY, double theWidth, double theHeight)
	{
		x = theX;
		y = theY;
		width = theWidth;
		height = theHeight;
	}

	/*SETTERS*/
	void setX(double theX) { x = theX; }
	void setY(double theY) { y = theY; }
	void setWidth(double theWidth) { width = theWidth; }
	void setHeight(double theHeight) { height = theHeight; }

	/*GETTERS*/
	double getX() const { return x; }
	double getY() const { return y; }
	double getWidth() const { return width; }
	double getHeight() const { return height; }

	const double getArea() { return width * height; }
	const double getPerimeter() { return (width * 2) + (height * 2); }

	/*get right boundary*/
	double getRightSide() const { return x + (width / 2); }
	/*get left boundary*/
	double getLeftSide() const { return x - (width / 2); }
	/*get top boundary*/
	double getTop() const { return y + (height / 2); }
	/*get bottom boundary*/
	double getBottom() const { return y - (height / 2); }

	
	/*"SPECIAL" GETTERS*/

	/*determines whether or not a certain point is contained inside the rectangle*/
	bool contains(double theX, double theY) const
	{
		/*determining if it's within the right side of the rectangle*/
		bool withinRightBorder = false;

		if (theX < getRightSide())
			withinRightBorder = true;

		/*determining if it's within the left side of the rectangle*/
		bool withinLeftBorder = false;

		if (theX > getLeftSide())
			withinLeftBorder = true;

		/*determining if it's below the top of the rectangle*/
		bool belowTopBorder = false;

		if (theY < getTop())
			belowTopBorder = true;

		/*determining if it's above the bottom of the rectangle*/
		bool aboveBottomBorder = false;

		if (theY > getBottom())
			aboveBottomBorder = true;

		/*return true only if all four above are true*/
		if (withinRightBorder && withinLeftBorder && belowTopBorder && aboveBottomBorder)
			return true;
		
			/*OTHERWISE: The point is not inside the rectangle; return false*/
			return false;
	}

	/*determines whether or not a certain rectangle is inside this rectangle*/
	bool contains(const Rectangle2D &r) const
	{
		/*is it within the right boundary?*/
		bool isWithinRight = false;

		if (r.getRightSide() < this->getRightSide())
			isWithinRight = true;

		/*is it within the left boundary?*/
		bool isWithinLeft = false;

		if (r.getLeftSide() > this->getLeftSide())
			isWithinLeft = true;

		/*is it below the top?*/
		bool isBelowTop = false;

		if (r.getTop() < this->getTop())
			isBelowTop = true;

		/*is it above the bottom?*/
		bool isAboveBottom = false;

		if (r.getBottom() > this->getBottom())
			isAboveBottom = true;

		/*return true only if all four above are true*/
		if (isWithinRight && isWithinLeft && isBelowTop && isAboveBottom)
			return true;

			/*OTHERWISE: It is not contained inside this rectangle; return false*/
			return false;
	}

	/*determines whether or not a certain rectangle overlaps with this rectangle*/
	bool overlaps(const Rectangle2D &r) const
	{
		/*IF ONE (OR BOTH) OF THE FOLLOWING CONDITIONS IS TRUE, THEY DO NOT OVERLAP*/

		/*If the vertical distance between the two rectangles' centers is greater than the sum
		of half of each of their heights, they do not overlap*/
		if (abs(this->y - r.getY()) > ((this->height / 2) + (r.getHeight() / 2)))
			return false;

		/*If the horizontal distance between the two rectangles' centers is greater than the sum
		of half of each of their heights, they do not overlap*/
		if (abs(this->x - r.getX()) > ((this->height / 2) + (r.getHeight() / 2)))
			return false;

		/*OTHERWISE (if both conditions are false): It DOES overlap; return true*/
		return true;
			
	}
};

#endif
