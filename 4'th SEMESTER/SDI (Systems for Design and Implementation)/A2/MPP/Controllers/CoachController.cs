using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using MPP.Models;

namespace MPP.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class CoachController : ControllerBase
    {
        private readonly BodyBuildersDatabasesContext _dbContext;

        public CoachController(BodyBuildersDatabasesContext dbContext)
        {
            _dbContext = dbContext;
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<Coach>>> GetAll()
        {
            if (_dbContext.Coaches == null)
                return NotFound();

            return await _dbContext.Coaches.ToListAsync();
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<Coach>> GetById(int id)
        {
            if (_dbContext.Coaches == null)
            {
                return NotFound();
            }
            var coach = await _dbContext.Coaches.FindAsync(id);

            if (coach == null)
            {
                return NotFound();
            }

            return coach;
        }

        [HttpPost]
        public async Task<ActionResult<Coach>> Create(Coach coach)
        {
            _dbContext.Coaches.Add(coach);
            await _dbContext.SaveChangesAsync();
            return CreatedAtAction(nameof(GetById), new { id = coach.Id }, coach);
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> Update(int id, Coach coach)
        {
            if (id != coach.Id)
            {
                return BadRequest();
            }
            _dbContext.Entry(coach).State = EntityState.Modified;

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
            return (_dbContext.Coaches?.Any(x => x.Id == id)).GetValueOrDefault();
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int id)
        {
            var coach = await _dbContext.Coaches.FindAsync(id);
            if (coach == null)
            {
                return NotFound();
            }
            _dbContext.Coaches.Remove(coach);
            await _dbContext.SaveChangesAsync();
            return NoContent();
        }
    }

}
