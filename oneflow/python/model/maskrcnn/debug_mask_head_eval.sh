rm -r eval_dump
export CUDA_VISIBLE_DEVICES=3
# export CUDA_LAUNCH_BLOCKING=1
python maskrcnn.py -mask_head_eval -load="/model_zoo/detection/mask_rcnn_R_50_FPN_1x/snapshot/"