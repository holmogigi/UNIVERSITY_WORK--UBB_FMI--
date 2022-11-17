public class Main
{
    public static void main(String args[])
    {

            Repository repo = new Repository(8);
            Controller controller = new Controller(repo);
            View view = new View(controller);
            view.app();

    }
}
