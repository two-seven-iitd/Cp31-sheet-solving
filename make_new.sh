#!/bin/bash
#chmod +x make_new.sh
if [ -z "$1" ]; then
    echo "Usage: ./scaffold.sh <Name>"
    exit 1
fi

NAME="$1"
ROOT="$(cd "$(dirname "$0")" && pwd)"
TARGET="$ROOT/$NAME"

if [ -d "$TARGET" ]; then
    echo "Error: Folder '$NAME' already exists at $TARGET" >&2
    exit 1
fi

mkdir "$TARGET"

echo "# Good Concepts" > "$TARGET/Good_Concepts.md"
echo "# Good Question" > "$TARGET/Good_Questions.md"
echo "## Pending to Solve/Brainstorm" > "$TARGET/README.md"

echo "Created folder '$NAME' with Good_Concepts.md, Good_Questions.md, README.md"