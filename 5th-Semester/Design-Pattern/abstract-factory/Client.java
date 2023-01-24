interface WidgetFactory {
	ScrollBar createScrollBar();
	Window createWindow();
}

class MotifWidgetFactory implements WidgetFactory {
	public ScrollBar createScrollBar(){
		return new MotifScrollBar();
	}	
	public Window createWindow(){
		return new MotifWindow();
	}
}

class PMWidgetFactory implements WidgetFactory {
	public ScrollBar createScrollBar(){
		return new PMScrollBar();
	}	
	public Window createWindow(){
		return new PMWindow();
	}
}


interface Window{}
class PMWindow implements Window{
	PMWindow(){
		System.out.println("PM Window is being created");
	}
}
class MotifWindow implements Window{
	MotifWindow(){
		System.out.println("Motif Window is being created");
	}
}

interface ScrollBar{}
class PMScrollBar implements ScrollBar{
	PMScrollBar(){
		System.out.println("PM Scrollbar is being created");
	}
}
class MotifScrollBar implements ScrollBar{
	MotifScrollBar(){
		System.out.println("Motif Scrollbar is being created");
	}
}


public class Client{
	public static void main(String[] args){
		WidgetFactory w = new PMWidgetFactory();
		w.createScrollBar();
		w.createWindow();
	}
}
