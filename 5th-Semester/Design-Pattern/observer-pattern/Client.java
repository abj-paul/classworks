public class Client {
    public static void main(String[] args) {
        Observer observer1 = new Observer("Abhijit Paul");
        Observer observer2 = new Observer("Labonnya");
        Observer observer3 = new Observer("Sifat");
        Observer observer4 = new Observer("Tashfia");

        Subject subject = new ConcreteSubject();
        subject.attach(observer1);
        subject.attach(observer2);
        subject.attach(observer3);
        subject.attach(observer4);

        subject.setState(new SubjectState("Tour"));
        subject.setState(new SubjectState("Adda"));
        subject.setState(new SubjectState("Games"));
    }
}
