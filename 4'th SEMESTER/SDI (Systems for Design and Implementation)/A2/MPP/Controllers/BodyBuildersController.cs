using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using MPP.Models;

namespace MPP.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class BodyBuildersController : ControllerBase
    {
        private readonly BodyBuildersDatabasesContext _dbContext;

        public BodyBuildersController(BodyBuildersDatabasesContext dbContext)
        {
            _dbContext = dbContext;
        }

        [HttpGet]
        public async Task<ActionResult<IEnumerable<Bodybuilder>>> GetAll()
        {
            if (_dbContext.Bodybuilders == null)
                return NotFound();

            return await _dbContext.Bodybuilders.ToListAsync();
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<Bodybuilder>> GetById(int id)
        {
            if (_dbContext.Bodybuilders == null)
            {
                return NotFound();
            }
            var body = await _dbContext.Bodybuilders.FindAsync(id);

            if (body == null)
            {
                return NotFound();
            }

            return body;
        }

        [HttpPost]
        public async Task<ActionResult<Bodybuilder>> Create(Bodybuilder bodybuilder)
        {
            _dbContext.Bodybuilders.Add(bodybuilder);
            await _dbContext.SaveChangesAsync();
            return CreatedAtAction(nameof(GetById), new { id=bodybuilder.Id}, bodybuilder);
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> Update(int id, Bodybuilder bodybuilder)
        {
            if (id != bodybuilder.Id)
            {
                return BadRequest();
            }
            _dbContext.Entry(bodybuilder).State = EntityState.Modified;

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
            return (_dbContext.Bodybuilders?.Any(x => x.Id == id)).GetValueOrDefault();
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int id)
        {
            var bodybuilder = await _dbContext.Bodybuilders.FindAsync(id);
            if (bodybuilder == null)
            {
                return NotFound();
            }
            _dbContext.Bodybuilders.Remove(bodybuilder);
            await _dbContext.SaveChangesAsync();
            return NoContent();
        }

        [HttpGet("filter/{Age}")]
        public async Task<IActionResult> FilterAge(int Age)
        {    
            if (_dbContext.Bodybuilders == null)
            {
                return NotFound();
            }
            var bd = await _dbContext.Bodybuilders.Where(X => X.Age > Age).ToListAsync();
            if (bd == null)
            {
                return NotFound();
            }
            return Ok(bd);
        }

    }
}