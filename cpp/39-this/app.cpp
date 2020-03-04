#include<iostream>

class Entity{
public:
	int x;
	Entity(int x);
	void reassign(int x);
};

void print_entity(Entity* e){
	std::cerr<<e->x<<std::endl;
}

Entity::Entity(int x){
	// The meaning of 'this': a pointer to the
	// current object (not the class)
	Entity* isto=this;

	// equivalent to this->x=x;
	isto->x=x;
	print_entity(this);
}

void Entity::reassign(int x){
	// Using the dot
	(*this).x=x;
	print_entity(this);
}

int main(){
	Entity e(13);
	e.reassign(19);
	return 0;
}
