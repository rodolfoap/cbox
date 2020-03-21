float minDistance = 2 * radius;
class Ball {
	PVector position;
	PVector velocity;
	int name;
	float initialEnergy;
	float lastEnergy;

	// Constructor
	Ball(float x, float y, PVector v, int bName) {
		position = new PVector(x, y);
		velocity = v;
		initialEnergy = energy();
		name = bName;
		lastEnergy=energy();
	}

	void update() {
		position.add(velocity);
	}

	void display() {
		fill(color(0, 0, 0));
		ellipse(position.x, position.y, radius * 2, radius * 2);
		fill(color(0, 255, 0));
		text(this.name, position.x - 4, position.y + 4);
	}

	void checkBorderCollision() {
		if (position.y > height - radius) {
			position.y = height - radius;
			velocity.y *= -1;
		} else if (position.y < radius) {
			position.y = radius;
			velocity.y *= -1;
		} else if (position.x < radius) {
			position.x = radius;
			velocity.x *= -1;
		} else if (position.x > width - radius) {
			position.x = width - radius;
			velocity.x *= -1;
		}
	}

	void checkBallCollision(Ball other) {
		// if (maxInteraction>0 && interaction>=maxInteraction) noLoop();
		PVector distanceVect = PVector.sub(other.position, position);
		float distanceVectMag = distanceVect.mag();
		if (distanceVectMag < minDistance) {	// Collision!
			interaction++;
			// before changing the speed, let's save the previous energy
			lastEnergy=energy();
			// Correct distance to avoid overlapping: move the other
			PVector distanceVectFixed=distanceVect.copy().normalize().mult(minDistance-distanceVect.mag());
			other.position.add(distanceVectFixed);
			// Rotate both speeds to emulate bouncing on a vertical wall
			velocity.rotate(-distanceVectFixed.heading());
			other.velocity.rotate(-distanceVectFixed.heading());
			// Then, simply exchange horizontal speeds
			float tempX = velocity.x;
			velocity.x = other.velocity.x;
			other.velocity.x = tempX;
			// Rotate back to original coordinates
			velocity.rotate(distanceVectFixed.heading());
			other.velocity.rotate(distanceVectFixed.heading());
			//calculateEntropy();
		}
	}

	float energy() {
		return sq(velocity.mag()) / 2;
	}
}

// Choose the balls number. Careful: you would need to define its initial locations.
int totalBalls=40;

// Choose the ball radius; mass is always 1.
int radius=12;

int interaction=0, lastX=0, lastY=0;
//int rWall=width
float totalEnergy = 0;
float totalEntropy = 0;
Ball[] balls=new Ball[totalBalls];
int[] entropy;

void setup() {
	size(1000, 400);
	interaction=0;
	// rWall=radius*4;
	entropy=new int[width];
	// Ball 0 has the energy to disperse.
	balls[0]=new Ball(radius*1.5, radius*1.5, new PVector(3, 4), 0);
	for (int number=1; number<totalBalls; number++)
		// Initially, we need energy>0 in order to have a positive entropy.
		balls[number]=new Ball(radius*3 + number*radius*2.5, radius*1.5, new PVector(0, 0.01), number);
		//calculateEntropy();
}

void draw() {
	background(0);
	stroke(color(0, 255, 0));
	for (Ball b : balls) {
		b.update();
		b.display();
		b.checkBorderCollision();
	}
	for (int i=0; i<balls.length; i++) {
		for (int j=i+1; j<balls.length; j++) {
			balls[i].checkBallCollision(balls[j]);
		}
	}
}
