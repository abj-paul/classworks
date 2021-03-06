package Basic;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
		test();
		}catch(Exception e) {e.printStackTrace();}
	}
	public static void test() throws Exception{
		Belief belief = new Belief("China");
		
		Class cls = belief.getClass();
		System.out.println("The class name is="+cls.getName());

		Constructor constructor = cls.getConstructor();
        System.out.println("The name of constructor is " +constructor.getName());
        
        Method[] methods = cls.getMethods();
        for(Method method: methods) {
        	System.out.println(method.getName());
        }
        
        Method methodcall1 = cls.getDeclaredMethod("showCastle");
        methodcall1.setAccessible(true);
        methodcall1.invoke(belief);
        methodcall1.invoke(belief);
        methodcall1.invoke(belief);
        
        Field[] fieldList = cls.getDeclaredFields();
        for(Field field: fieldList){
        	field.setAccessible(true);
        	System.out.println(field.getName());
        }
        
	}

}
