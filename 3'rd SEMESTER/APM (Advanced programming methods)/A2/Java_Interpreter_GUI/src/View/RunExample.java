package View;
import Controller.Controller;
import Exceptions.MyException;

import java.io.IOException;

public class RunExample extends Command
{
    private Controller ctr;

    public RunExample(String key, String desc, Controller ctr)
    {
        super(key, desc);
        this.ctr = ctr;
    }

    @Override
    public void execute()
    {
        try {
            ctr.all_steps();
        }
        catch(MyException exc) {
            System.out.println(exc.getMessage());
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
