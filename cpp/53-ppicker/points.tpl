%YAML:1.0
---
image_points: !!opencv-matrix
    rows: {{rows}}
    cols: 2
    dt: i
    data: [
        {{#coordxy}}
        {{x}}, {{y}},
        {{/coordxy}}
]
world_points: !!opencv-matrix
    rows: {{rows}}
    cols: 2
    dt: d
    data: [
        {{#coordll}}
        {{x}}, {{y}},
        {{/coordll}}
]
