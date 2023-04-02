package patterns;

public class Image {
    private String img_name = "default_image.png";
    private String description = "Default description of the image.";
   Image(){}
   public Image(String img_name, String description){
    this.description = description;
    this.img_name = img_name;
   } 

   public String toString(){
        return this.img_name + "," + this.description;
   }
}
