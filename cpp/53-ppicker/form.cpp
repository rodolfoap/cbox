class Form{
private:
	kainjow::mustache::data data;
	kainjow::mustache::data coordxy;
	kainjow::mustache::data coordll;
	void addcoords(kainjow::mustache::data& coordset, float x, float y){
		kainjow::mustache::data pair;
		pair.set("x", std::to_string(x));
		pair.set("y", std::to_string(y));
		coordset<<kainjow::mustache::data{pair};
	}
public:
	Form(): coordxy(kainjow::mustache::data::type::list), coordll(kainjow::mustache::data::type::list){}
	void addxy(float x, float y){ addcoords(coordxy, x, y); }
	void addll(float x, float y){ addcoords(coordll, x, y); }
	void render(){
		data.set("rows", "19");
		data.set("coordxy", coordxy);
		data.set("coordll", coordll);
		kainjow::mustache::mustache tpl{readFile("points.tpl")};
 		std::cerr<<tpl.render(data)<<std::endl;
	}
};
