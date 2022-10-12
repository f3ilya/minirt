reset
echo "camera: on x" &
cat data_test/camera/on_x.rt & ./miniRT data_test/camera/on_x.rt
echo "\n\ncamera: on y" &
cat data_test/camera/on_y.rt & ./miniRT data_test/camera/on_y.rt
echo "\n\ncamera: on z" &
cat data_test/camera/on_z.rt & ./miniRT data_test/camera/on_z.rt
echo "\n\ncamera: on xyz" &
cat data_test/camera/on_xyz.rt & ./miniRT data_test/camera/on_xyz.rt
reset