SELECT c.customer_id, c.customer_name
FROM customer c
JOIN shipment s ON c.customer_id = s.customer_id
JOIN current_delivery cd ON s.shipment_id = cd.shipment_id
JOIN delivery sd ON cd.current_delivery_id = sd.current_delivery_id
WHERE sd.delivery_status = 'DELIVERED'
  AND sd.vehicle_id = 'AAA1111'
  AND sd.current_delivery_id IN (
	SELECT scd.current_delivery_id
    FROM current_delivery scd
    JOIN delivery kd ON scd.current_delivery_id = kd.current_delivery_id
    WHERE kd.vehicle_id = 'AAA1111'
    AND kd.delivery_status = 'CRASH'
  )
ORDER BY cd.current_t DESC
LIMIT 1;
