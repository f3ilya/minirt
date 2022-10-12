reset
echo "translation: sphere 1st stape" &
cat data_test/translation/two_sphere_same_pos.rt & ./miniRT data_test/translation/two_sphere_same_pos.rt
echo "\n\ntranslation: sphere 2nd stape" &
cat data_test/translation/two_sphere_same_xy.rt & ./miniRT data_test/translation/two_sphere_same_xy.rt
echo "\n\ntranslation: sphere camera moving" &
cat data_test/translation/two_sphere_same_xy_camera_check.rt & ./miniRT data_test/translation/two_sphere_same_xy_camera_check.rt
reset

echo "rotation: cylinder" &
cat data_test/translation/cylindre_face.rt & ./miniRT data_test/translation/cylindre_face.rt
echo "\n\ntranslation: cylinder 90° rotation" &
cat data_test/translation/cylindre_rot_90.rt & ./miniRT data_test/translation/cylindre_rot_90.rt
reset