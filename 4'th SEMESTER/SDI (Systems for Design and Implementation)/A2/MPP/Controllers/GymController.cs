using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using MPP.Models;

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
        public async Task<ActionResult<IEnumerable<Gym>>> GetAll()
        {
            if (_dbContext.Gyms == null)
                return NotFound();

            return await _dbContext.Gyms.ToListAsync();
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<Gym>> GetById(int id)
        {
            if (_dbContext.Gyms == null)
            {
                return NotFound();
            }
            var gym = await _dbContext.Gyms.FindAsync(id);

            if (gym == null)
            {
                return NotFound();
            }

            return gym;
        }

        [HttpPost]
        public async Task<ActionResult<Gym>> Create(Gym gym)
        {
            _dbContext.Gyms.Add(gym);
            await _dbContext.SaveChangesAsync();
            return CreatedAtAction(nameof(GetById), new { id = gym.Id }, gym);
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> Update(int id, Gym gym)
        {
            if (id != gym.Id)
            {
                return BadRequest();
            }
            _dbContext.Entry(gym).State = EntityState.Modified;

            try
            {
                await _dbContext.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!CheckAvailable(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }
            return Ok();
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
    }
}
