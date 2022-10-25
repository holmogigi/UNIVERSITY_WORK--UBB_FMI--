/*
Tomatoes, peppers and eggplants are grown in a greenhouse.
To display all the vegetables with the higher weight of 0.2 kg.
*/

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.LogRecord;
import java.util.logging.Logger;

public class View
{
    private Controller controller;

    public View(Controller controller_)
    {
        this.controller=controller_;
    }

    public void print_menu()
    {
        System.out.printf("\n1.ADD a vegetable");
        System.out.printf("\n2.REMOVE a vegetable");
        System.out.printf("\n3.PRINT all vegetables");
        System.out.printf("\n4.SHOW all vegetables with weight > 0.2 kg");
        System.out.printf("\n0.EXIT\n");
        System.out.printf("\nINPUT: ");
    }

    private void add_vegetable() throws ExceptionClass
    {
        System.out.println("Vegetable type: ");
        Scanner read= new Scanner(System.in);
        String type= read.next();
        if(type.equals("tomato") || type.equals("pepper") || type.equals("eggplant"))
        {
            System.out.println("Weight: ");
            float weight=read.nextFloat();
            if (weight<=0.00f)
                throw new ExceptionClass("!ERROR! Invalid weight!");
            else
                this.controller.add(type,weight);
        }
        else
            throw new ExceptionClass("!ERROR! Invalid type!");
    }

    private void remove_vegetable() throws ExceptionClass
    {
        System.out.println("Vegetable index: ");
        Scanner read= new Scanner(System.in);
        int pos=read.nextInt();
        if (pos<0 || pos>this.controller.get_size()-1)
            throw new ExceptionClass("!ERROR! Invalid index!");
        else
            this.controller.remove(pos);
    }

    private void print_all()
    {
        IVegetables[] veg=this.controller.get_veg();;
        for (int i=0;i<this.controller.get_size();i++)
            System.out.println("Nr." + i + " " + veg[i].to_string());
    }

    private void print_filtered()
    {
        IVegetables[] good_list=this.controller.get_good();
        for (int i=0;i<good_list.length;i++)
            System.out.println("Nr." + i + " " + good_list[i].to_string());
    }


    private boolean check_digit(String test)
    {
        for (int i=0;i<test.length();i++)
        {

            if (!Character.isDigit(test.charAt(i)))
                return false;
        }
        return true;
    }

    public void app()
    {
        while (true)
        {
            try {
                print_menu();
                Scanner read = new Scanner(System.in);
                String input_S = read.next();
                while (check_digit(input_S)==false)
                {
                    System.out.println("!ERROR! Invalid input!");
                    print_menu();
                    String test=read.next();
                    input_S=test;
                }
                int input=Integer.parseInt(input_S);
                if (input == 1)
                {
                    add_vegetable();
                } else if (input == 2)
                {
                    remove_vegetable();
                } else if (input == 3)
                {
                    print_all();
                } else if (input == 4)
                {
                    print_filtered();
                } else if (input == 0)
                {
                    System.out.printf("Exiting...");
                    System.exit(0);
                }
                else
                    System.out.println("!ERROR! Wrong input!");
            } catch (ExceptionClass exceptionClass)
            {
                System.out.println(exceptionClass.getMessage());
                Logger.getLogger(exceptionClass.getMessage()).log(Level.SEVERE,"ERROR" + exceptionClass.getMessage());
            }
        }
    }
}
