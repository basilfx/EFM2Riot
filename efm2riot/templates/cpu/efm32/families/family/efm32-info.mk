# This file is automatically generated, and should not be changed. There is
# probably little reason to edit this file anyway, since it should already
# contain all information for the EFM32PG12B family of CPUs.

# Series - Architecture - Flash base - Flash size - SRAM base - SRAM size - Crypto? - TRNG? - Radio?
{% strip 3 %}
    {% align_with "=" %}
        {% for cpu in cpus %}
            EFM32_INFO_{{ cpu.cpu }} = {{ cpu_series }} cortex-{{ architecture }} {{ cpu.flash_base|hex(8) }} {{ cpu.flash_size|hex(8) }} {{ cpu.sram_base|hex(8) }} {{ cpu.sram_size|hex(8) }} {{ crypto|int }} {{ trng|int }} {{ radio|int }}
        {% endfor %}
    {% endalign_with %}
{% endstrip %}
