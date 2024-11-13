#!/bin/bash

#Function to Copy a File
copyFile(){
echo "Enter source file path: "
read src
echo "Enter destination File path: "
read dest

if cp "$src" "$dest"; then
echo "File copied from $src to $dest"
else
echo "Copying Failed"
fi
}

#Function to move a file
moveFile(){
echo "Enter a source file path: "
read src
echo "Enter destination file path: "
read dest

if mv "$src" "$dest"; then
echo "File moved from $src to $dest"
else
echo "Moving Failed"
fi
}

#Function to rename a file
renameFile(){
echo "Enter current file name: "
read src
echo "Enter new file name: "
read dest

if mv "$src" "$dest"; then
echo "File renamed from $src to $dest"
else
echo "Renaming Failed"
fi
}

#Function to delete a file
deleteFile(){
echo "Enter file name to be deleted: "
read file

if rm "$file"; then
echo "File $file deleted"
else
echo "Deleting Failed"
fi
}

while true; do
echo "File operations: "
echo "1. Copy File"
echo "2. Move File"
echo "3. Rename File"
echo "4. Delete File"
echo "Enter your choice: "
read choice

case $choice in
1)
copyFile
;;
2)
moveFile
;;
3)
renameFile
;;
4)
deleteFile
;;
5)
echo "Exiting Program"
exit 0
;;
*)
echo "Invalid Choice"
;;
esac
done
