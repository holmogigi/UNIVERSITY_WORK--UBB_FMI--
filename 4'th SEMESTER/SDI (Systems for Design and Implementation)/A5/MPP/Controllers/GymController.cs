using Microsoft.AspNetCore.Mvc;
using Microsoft.CodeAnalysis;
using Microsoft.EntityFrameworkCore;
using MPP.Database;
using MPP.DTOs;
using MPP.Models;
using NuGet.Packaging;
using System.Diagnostics;

namespace MPP.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class GymController : ControllerBase
    {
        private readonly BodyBuildersDatabasesContext _dbContext;

        public GymController(BodyBuildersDatabasesContext dbContext)
        {
            _dbContext = dbContext;
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<GymDTO>>> GetAll()
        {
            return await _dbContext.Gyms
                .Select(x => GymToDTO(x))
                .ToListAsync();
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<Gym>> GetById(int id)
        {
            if (_dbContext.Gyms == null)
                return NotFound();

            var gym = await _dbContext.Gyms
                .Include(x => x.Coaches)
                .FirstOrDefaultAsync(x => x.Id == id);

            if (gym == null)
                return NotFound();

            return gym;
        }

        [HttpPost]
        public async Task<ActionResult<GymDTO>> Create(GymDTO gymDTO)
        {
            // Validation
            if (gymDTO.Grade>10 || gymDTO.Grade<1)
                return BadRequest("!ERROR! Ivalid Grade!");

            var gym = new Gym
            {
                Name = gymDTO.Name,
                Location = gymDTO.Location,
                Memembership = gymDTO.Memembership,
                Grade = gymDTO.Grade
            };

            _dbContext.Gyms.Add(gym);
            await _dbContext.SaveChangesAsync();

            return CreatedAtAction(
                nameof(GetById),
                new { id = gym.Id },
                GymToDTO(gym));
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> Update(int id, GymDTO gymDTO)
        {
            if (id != gymDTO.Id)
            {
                return BadRequest();
            }

            var gym = await _dbContext.Gyms.FindAsync(id);
            if (gym == null)
                return NotFound();

            gym.Name = gymDTO.Name;
            gym.Location = gymDTO.Location;
            gym.Memembership = gymDTO.Memembership;
            gym.Grade = gymDTO.Grade;

            try
            {
                await _dbContext.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException) when (!gymExists(id))
            {
                return NotFound();
            }
            return NoContent();
        }

        private bool CheckAvailable(int id)
        {
            return (_dbContext.Gyms?.Any(x => x.Id == id)).GetValueOrDefault();
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int id)
        {
            var gym = await _dbContext.Gyms.FindAsync(id);
            if (gym == null)
            {
                return NotFound();
            }
            _dbContext.Gyms.Remove(gym);
            await _dbContext.SaveChangesAsync();

            return NoContent();
        }

        private static GymDTO GymToDTO (Gym gym) => 
            new GymDTO 
        {
            Id = gym.Id, 
            Name = gym.Name, 
            Location = gym.Location,
            Memembership = gym.Memembership,
            Grade = gym.Grade
        };

        private bool gymExists(int id)
        {
            return _dbContext.Gyms.Any(x => x.Id == id);
        }


        [HttpGet("order")]
        public async Task<ActionResult<IEnumerable<Gym>>> GetGymAverageAge()
        {
            if (_dbContext.Gyms == null)
                return NotFound();
   
            var GymOrderedByAge = await _dbContext.Gyms
                .Include(g => g.Coaches)
                .Select(g => new
                {
                    Gym = g,
                    AvgCoachAge= g.Coaches.Average(c => c.Age)
                })
                .OrderByDescending(g => g.AvgCoachAge)
                .Select(g => g.Gym)
                .ToListAsync();

            if (GymOrderedByAge == null)
                return NotFound();

            return GymOrderedByAge;
        }

        [HttpGet("MinCoachAge")]
        public async Task<ActionResult<IEnumerable<Gym>>> GetGymMiniAge()
        {
            if (_dbContext.Gyms == null)
                return NotFound();

            var GymOrderedByAge = await _dbContext.Gyms
                .Include(g => g.Coaches)
                .Select(g => new
                {
                    Gym = g,
                    MinCoachAge = g.Coaches.Min(c => c.Age)
                })
                .OrderByDescending(g => g.MinCoachAge)
                .Select(g => g.Gym)
                .ToListAsync();

            if (GymOrderedByAge == null)
                return NotFound();

            return GymOrderedByAge;
        }


        [HttpGet("filter/{Grade}")]
        public async Task<ActionResult<IEnumerable<GymDTO>>> FilterGrade(int Grade)
        {
            if (_dbContext.Gyms == null)
            {
                return NotFound();
            }
            return await _dbContext.Gyms.
                Where(X => X.Grade > Grade)
                .Select(X => GymToDTO(X))
                .ToListAsync();
        }


        [HttpPost("{id}/gyms")]
        public async Task<ActionResult<GymDTO>> PostCoachGym(int id, IEnumerable<CoachDTO> coachesDto)
        {
            var gym = await _dbContext.Gyms.FindAsync(id);
            if (gym == null)
                return NotFound();

            foreach (var coachDTO in coachesDto)
            {
                var coach = new Coach
                {
                    Id = coachDTO.Id,
                    Name = coachDTO.Name,
                    Age = coachDTO.Age,
                    Rate = coachDTO.Rate,
                    GymId = id
                };
                _dbContext.Coaches.Add(coach);
            }
            await _dbContext.SaveChangesAsync();

            return CreatedAtAction(
                nameof(GetById),
                new { id = gym.Id},
                GymToDTO(gym)
                );
        }

    }
}
