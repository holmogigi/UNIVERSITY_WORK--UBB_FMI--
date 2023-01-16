package View;

public class ExitCommand extends Command
{
    public ExitCommand(String key, String desc)
    {
        super(key, desc);
    }

    @Override
    public void execute()
    {
        System.out.println("Exiting...");
        System.exit(0);
    }
}
