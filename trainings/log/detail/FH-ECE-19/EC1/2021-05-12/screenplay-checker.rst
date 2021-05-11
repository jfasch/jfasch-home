.. include:: <mmlalias.txt>


Screenplay Checker
==================

* Pull in ``snippets/students.py``. Goal is to compute from those
  names (containing umlauts) the directory names.

  * iterate (*tuple unpacking*) over the tuples in the list.
  * ``str.replace()`` umlauts, upper and lower.
  * observe code duplication.
  * |longrightarrow| function ``transform()``

* Once transformed ...

  * Take from the commmandline (``sys.argv[1]``) the repository root
  * Compute the path to each user's supposed ``digit`` program.

    * First, using dumb string additions and ``/``
    * Replace with ``os.path.join()`` (|longrightarrow| look it up in
      the docs)
    * Check existence using ``os.path.isfile()``
    * Raise ``RuntimeError`` if not there

* Whole program stops on first failure |longrightarrow| collect errors
  and move on to next user
  
  * |longrightarrow| ``except``, gathering errors in a list
  * output pass/fail once all users iterated

* Run prog

  * In the shell, run one prog. Show what "capture stdout" means, by
    redirecting to a file.
  * ``.../digit 7 | cat > file``: aha, pipe to somewhere, and use that
    instead.
  * Enter ``subprocess``. Read docs.
  * Find that most progs are not executable. Catch that.

    * Raise ``RuntimeError`` inside ``except`` block.

  * Find that ``completed.stdout`` is ``bytes``. OMG, explain
    encoding. Notebook.

* Module ``students``

  * Raw user list
  * Function to convert to exercise dirs.
  * What else?
