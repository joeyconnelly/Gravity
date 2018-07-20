SET tfile="compile"
SET "out=%tfile%.out"
SET "err=%tfile%.err"

SET main="gravity"
SET "rom=%main%.gb"
SET "code=%main%.c"

DEL %rom%
DEL %out%
DEL %err%

lcc -o %rom% %code% >%out% 2>%err%