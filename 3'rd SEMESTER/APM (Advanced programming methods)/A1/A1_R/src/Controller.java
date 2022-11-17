public class Controller
{
    private IRepository repo;

    public Controller(IRepository repo_)
    {
        this.repo=repo_;
    }

    public void add(String vegetable, float weight)
    {
        if (vegetable.equals("eggplant"))
        {
            Eggplant eggplant=new Eggplant(weight);
            this.repo.add(eggplant);
        }
        else if (vegetable.equals("tomato"))
        {
            Tomato tomato=new Tomato(weight);
            this.repo.add(tomato);
        }
        else if (vegetable.equals("pepper"))
        {
            Pepper pepper=new Pepper(weight);
            this.repo.add(pepper);
        }
    }

    public void remove(int pos)
    {
        this.repo.remove(pos);
    }

    public IVegetables[] get_veg()
    {
        return this.repo.get_all();
    }

    public int get_size()
    {
        return this.repo.get_size();
    }

    public IVegetables[] get_good()
    {
        IVegetables[] repo_copy= new IVegetables[this.repo.get_size()];
        int size=0;
        for (IVegetables vegetables: this.repo.get_all())
        {
            if (vegetables!=null)
                if (vegetables.get_weight() > 0.20f)
                    repo_copy[size++]=vegetables;
        }
        IVegetables[] good_list=new IVegetables[size];
        System.arraycopy(repo_copy,0,good_list,0,size);
        return good_list;
    }

}
