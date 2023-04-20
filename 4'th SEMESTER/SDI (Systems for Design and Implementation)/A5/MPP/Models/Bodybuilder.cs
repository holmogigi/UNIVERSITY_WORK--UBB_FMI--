namespace MPP.Models
{
    public class Bodybuilder
    {
        public int Id { get; set; }
        public string? Name { get; set; }
        public int Age { get; set; }
        public int Weight { get; set; }
        public int Height { get; set; }
        public string? Division { get; set; }

        public virtual ICollection<Contest> Contests { get; set; } = null!;
    }
}
      