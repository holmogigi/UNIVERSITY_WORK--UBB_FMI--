using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using MPP.Database;
using MPP.DTOs;
using MPP.Models;
using System.Drawing.Text;

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
        public async Task<ActionResult<IEnumerable<BodybuilderDTO>>> GetAll()
        {

            return await _dbContext.Bodybuilders.Select(b => BdtoDTO(b)).ToListAsync();
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<BodybuilderDTO>> GetById(int id)
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

            return BdtoDTO(body);
        }

        [HttpPost]
        public async Task<ActionResult<BodybuilderDTO>> Create(BodybuilderDTO bodybuilder)
        {
            // Validation
            if (bodybuilder.Age<1 || bodybuilder.Age > 122)
                return BadRequest("!ERROR! Invalid Age!");

            var Body = new Bodybuilder
            {
                Name = bodybuilder.Name,
                Age = bodybuilder.Age,
                Weight = bodybuilder.Weight,
                Height = bodybuilder.Height,
                Division = bodybuilder.Division
            };

            _dbContext.Bodybuilders.Add(Body);
            await _dbContext.SaveChangesAsync();

            return CreatedAtAction(
                nameof(GetById),
                new { id = Body.Id },
                BdtoDTO(Body));
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> Update(int id, BodybuilderDTO bodybuilder)
        {
            if (id != bodybuilder.Id)
            {
                return BadRequest();
            }

            var bdToUpate = await _dbContext.Bodybuilders.FindAsync(id);
            if (bdToUpate == null)
            {
                return NotFound();
            }

            bdToUpate.Name = bodybuilder.Name;
            bdToUpate.Age = bodybuilder.Age;
            bdToUpate.Weight = bodybuilder.Weight;
            bdToUpate.Height = bodybuilder.Height;
            bdToUpate.Division = bodybuilder.Division;

            try
            {
                await _dbContext.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException) when (!BdExists(id))
            {
                return NotFound();
            }

            return NoContent();
        }

        private bool CheckAvailable(int id)
        {
            return (_dbContext.Bodybuilders?.Any(x => x.Id == id)).GetValueOrDefault();
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> Delete(int id)
        {
            if (_dbContext == null)
            {
                return NotFound();
            }
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
        public async Task<ActionResult<IEnumerable<BodybuilderDTO>>> FilterAge(int Age)
        {
            if (_dbContext.Bodybuilders == null)
            {
                return NotFound();
            }
            return await _dbContext.Bodybuilders.
                Where(X => X.Age > Age)
                .Select(X => BdtoDTO(X))
                .ToListAsync();
        }
        

        [HttpPost("{bdId}/contest/{coachId}")]
        public async Task<ActionResult<ContestDTO>> PostContest (int bdId, int coachId, ContestDTO contest)
        {
            var bd = await _dbContext.Bodybuilders.FindAsync (bdId);
            var coach = await _dbContext.Coaches.FindAsync (coachId);

            if ( bd==null || coach==null)
                return NotFound();

            var contestt = new Contest
            {
                Bodybuilder = bd,
                Coach = coach,
                DateTime = DateTime.Now,
                Name = contest.Name,
                Location = contest.Location,
            };

            _dbContext.Contests.Add (contestt);
            await _dbContext.SaveChangesAsync ();

            return CreatedAtAction(nameof(PostContest), contest);
        }

        private static BodybuilderDTO BdtoDTO(Bodybuilder bd) =>
            new BodybuilderDTO
            {
                Id = bd.Id,
                Name = bd.Name,
                Age = bd.Age,
                Weight = bd.Weight,
                Height = bd.Height,
                Division = bd.Division
            };

         private bool BdExists(int id)
            {
                return (_dbContext.Bodybuilders?.Any(b => b.Id == id)).GetValueOrDefault();
            }
    }
}