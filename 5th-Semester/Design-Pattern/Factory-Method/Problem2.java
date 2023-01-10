interface Metal{}
class SS implements Metal{}
class Raw implements Metal{}

abstract class Building {
	abstract void makeFloor();
	abstract void makeFoundation();
}

class SchoolBuilding extends Building{
	void makeFloor(){
		Metal metal = new SS();
		metal.bend();
		metal.process();
		metal.hammer();
		metal.transport();
		metal.color();
		metal.useInBlock();
		metal.align();
	}

	void makeFoundation(){
		Metal metal = new SS();
		metal.bend();
		metal.process();
		metal.hammer();
		metal.transport();
		metal.color();
		metal.useInBlock();
		metal.align();
	}
}

class VIPBuilding extends Building{
	void makeFloor(){
		Metal metal = new Raw();
		metal.bend();
		metal.process();
		metal.hammer();
		metal.transport();
		metal.color();
		metal.useInBlock();
		metal.align();
	}
	void makeFoundation(){
		Metal metal = new SS();
		metal.bend();
		metal.process();
		metal.hammer();
		metal.transport();
		metal.color();
		metal.useInBlock();
		metal.align();
	}
}

