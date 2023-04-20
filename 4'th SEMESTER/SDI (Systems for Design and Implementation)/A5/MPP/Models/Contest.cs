namespace MPP.Models
{
    public class Contest
    {
        public DateTime DateTime { get; set; }
        
        public string? Name { get; set; }

        public string? Location { get; set; }

        public int CoachId { get; set; }

        public int BodybuilderId { get; set; }

        public  Coach? Coach { get; set; } = null!;

        public  Bodybuilder? Bodybuilder { get; set; } = null!;
    }
}
