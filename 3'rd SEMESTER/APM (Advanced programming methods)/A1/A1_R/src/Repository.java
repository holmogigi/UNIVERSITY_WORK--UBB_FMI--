public class Repository implements IRepository
{
    private IVegetables[] vegetables;
    private int nr;

    public Repository(int size)
    {
        this.vegetables=new IVegetables[size];
        this.nr=0;
    }

    private void resize()
    {
        IVegetables[] new_vegetables= new IVegetables[this.nr*2+1];
        System.arraycopy(this.vegetables,0,new_vegetables,0,this.vegetables.length);
        this.vegetables=new_vegetables;
    }

    @Override
    public void add(IVegetables vegetables)
    {
        if (this.nr==this.vegetables.length)
        {resize();}
        this.vegetables[this.nr]=vegetables;
        this.nr++;
    }

    @Override
    public void remove(int pos)
    {
        IVegetables[] anotherArray = new IVegetables[this.nr - 1];
        for (int i=0, k=0; i<this.nr; i++)
        {
            if (i != pos)
                anotherArray[k++] = this.vegetables[i];
        }
        this.vegetables=anotherArray;
        this.nr--;
    }

    @Override
    public IVegetables[] get_all()
    {
        return this.vegetables;
    }

    @Override
    public int get_size()
    {
        return this.nr;
    }
}
