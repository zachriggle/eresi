/*
** implicit.c for elfsh
** 
** Started on  Tue Feb 18 06:45:35 2003 mayhem
**
** $Id: implicit.c,v 1.2 2007-03-07 16:45:35 thor Exp $
**
*/
#include "revm.h"



/* Load the working files */
void				vm_load_cwfiles()
{
  char				logbuf[BUFSIZ];

  PROFILER_IN(__FILE__, __FUNCTION__, __LINE__);

  if (world.state.input == NULL)
    {
      cmd_help();
      vm_exit (-1);
    }
  world.curjob->current = (world.state.output != NULL ? 
			   elfsh_map_obj(world.state.input) :
			   elfsh_load_obj(world.state.input));
  if (world.curjob->current == NULL)				
    {								
      perror(world.state.input);					
      vm_exit(-1);						
    }					

  hash_add(&world.curjob->loaded, world.curjob->current->name,
	   world.curjob->current);
  hash_add(&file_hash, world.curjob->current->name, 
	   (void *) world.curjob->current);

  if (!world.state.vm_quiet)	
    {
      snprintf(logbuf, BUFSIZ - 1, "\n [*] Object %s has been loaded (%s) \n\n", 
	       world.state.input, 
	       (world.state.output != NULL ? "O_RDWR" : "O_RDONLY"));
      vm_output(logbuf);
    }

  PROFILER_OUT(__FILE__, __FUNCTION__, __LINE__);
}




/* Unload (and save if asked) files */
int				vm_unload_cwfiles()
{
  char				logbuf[BUFSIZ];

  PROFILER_IN(__FILE__, __FUNCTION__, __LINE__);

  if (world.state.output)
    switch (elfsh_save_obj(world.curjob->current, world.state.output))
      {
      case 0:
	if (!world.state.vm_quiet)
	  {
	    snprintf(logbuf, BUFSIZ - 1,
		     " [*] Object %s saved successfully \n\n",
		     world.state.output);
	    vm_output(logbuf);
	  }
	break;
      default:
	snprintf(logbuf, BUFSIZ - 1,
		 " [*] Unable to save modified object in %s \n\n", 
		 world.state.output);
	vm_output(logbuf);
	PROFILER_ERR(__FILE__, __FUNCTION__, __LINE__, 
			  "Failed to save object", (-1));
      }
  else
    {
      elfsh_unload_obj(world.curjob->current);
      if (!world.state.vm_quiet)
	{
	  snprintf(logbuf, BUFSIZ - 1,
		   " [*] Object %s unloaded \n\n", world.state.input);
	  vm_output(logbuf);
	}
    }
  PROFILER_ROUT(__FILE__, __FUNCTION__, __LINE__, 0);
}




/* Do all implicit operation when calling elfsh from a script */
int		vm_implicit(revmcmd_t *actual)
{

  PROFILER_IN(__FILE__, __FUNCTION__, __LINE__);

  /* If the requested command does not need a current pointer */
  if (actual && !actual->wflags)
    PROFILER_ROUT(__FILE__, __FUNCTION__, __LINE__, 0);

  /* Load implicit current file */
  else if (world.state.vm_mode == REVM_STATE_CMDLINE && 
	   world.curjob->current == NULL)
    {
      if (!world.state.vm_sourcing)
	vm_load_cwfiles();
      if (!world.curjob->current)
	{
	  cmd_help();
	  vm_exit(-1);
	}
    }
  
  /* Do error in imode if current is NULL */
  else if (((world.state.vm_mode == REVM_STATE_INTERACTIVE ||
	     world.state.vm_mode == REVM_STATE_SCRIPT) && 
	    !world.curjob->current))
    {
      cmd_dolist();
      PROFILER_ERR(__FILE__, __FUNCTION__, __LINE__, "No file loaded", -1);
    }

  /* We need to set it here since the CURRENT object can change */
  asm_set_resolve_handler(&world.proc, asm_do_resolve, world.curjob->current);

  PROFILER_ROUT(__FILE__, __FUNCTION__, __LINE__, 0);
}
















