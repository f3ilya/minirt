reset
echo "multi-objets: outdoor" &
cat data_test/multi_objects/outdoor.rt & ./miniRT data_test/multi_objects/outdoor.rt
echo "\n\nmulti-objets: indoor with light" &
cat data_test/multi_objects/indoor_w_light.rt & ./miniRT data_test/multi_objects/indoor_w_light.rt
echo "\n\nmulti-objets: indoor without light" &
cat data_test/multi_objects/indoor_wo_light.rt & ./miniRT data_test/multi_objects/indoor_wo_light.rt
