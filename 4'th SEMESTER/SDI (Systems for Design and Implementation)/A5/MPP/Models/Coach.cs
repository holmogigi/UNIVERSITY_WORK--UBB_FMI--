using System.ComponentModel.DataAnnotations.Schema;
namespace MPP.Models
{
    public class Coach
    {
        public int Id { set; get; }
        public string? Name { set; get; }
        public int Age { set; get; }
        public int Rate { set; get; }

        public int GymId { set; get; }

        public virtual Gym Gym { set; get; } = null!;

        public virtual ICollection<Contest> Contests { set; get; } = null!;
    }
}