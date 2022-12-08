package View;
import Exceptions.MyException;
import Model.ADT.AdtDictionary;
import Model.ADT.AdtDictionaryInterface;
import java.util.Scanner;

public class TextMenu
{
    private AdtDictionaryInterface<String, Command> commands;

    public TextMenu()
    {
        this.commands = new AdtDictionary<>();
    }
    public void addCommand(Command c) {
        commands.put(c.getKey(), c);
    }
    private void printMenu() {
        for(Command com : commands.values()) {
            String line = String.format("%4s : %s",com.getKey(), com.getDescription());
            System.out.println(line);
        }
    }
    public void show() {
        Scanner scanner = new Scanner(System.in);
        while(true) {
            printMenu();
            System.out.printf(">>");
            String key = scanner.nextLine();
            try{
            Command com  = commands.lookup(key);
            com.execute();}
            catch (MyException e)
            {
                System.out.println("!ERROR! Ivalid option!");
            }
        }
    }
}
