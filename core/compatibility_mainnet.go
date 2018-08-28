package core

// CompatibilityMainNet ..
type CompatibilityMainNet struct {
	transferFromContractEventRecordableHeight uint64

	acceptFuncAvailableHeight uint64

	randomAvailableHeight uint64

	dateAvailableHeight uint64

	recordCallContractResultHeight uint64

	nvmMemoryLimitWithoutInjectHeight uint64

	wsResetRecordDependencyHeight uint64

	v8JSLibVersionControlHeight uint64

	transferFromContractFailureEventRecordableHeight uint64

	newNvmExeTimeoutConsumeGasHeight uint64

	v8JSLibVersionHeightMap *V8JSLibVersionHeightMap

	nvmGasLimitWithoutTimeoutHeight uint64

	transferFromContractFailureEventRecordableHeight2 uint64

	wsResetRecordDependencyHeight2 uint64
}

// NewCompatibilityMainNet ..
func NewCompatibilityMainNet() Compatibility {
	return &CompatibilityMainNet{
		transferFromContractEventRecordableHeight:        225666,
		acceptFuncAvailableHeight:                        225666,
		randomAvailableHeight:                            225666,
		dateAvailableHeight:                              225666,
		recordCallContractResultHeight:                   225666,
		nvmMemoryLimitWithoutInjectHeight:                306800,
		wsResetRecordDependencyHeight:                    306800,
		v8JSLibVersionControlHeight:                      467500,
		transferFromContractFailureEventRecordableHeight: 467500,
		newNvmExeTimeoutConsumeGasHeight:                 467500,
		v8JSLibVersionHeightMap: &V8JSLibVersionHeightMap{
			Data: map[string]uint64{
				"1.0.5": 467500, // v8JSLibVersionControlHeight
				"1.1.0": 600000,
			},
			DescKeys: []string{"1.1.0", "1.0.5"},
		},
		nvmGasLimitWithoutTimeoutHeight:                   600000,
		wsResetRecordDependencyHeight2:                    600000,
		transferFromContractFailureEventRecordableHeight2: 600000,
	}
}

// TransferFromContractEventRecordableHeight ..
func (c *CompatibilityMainNet) TransferFromContractEventRecordableHeight() uint64 {
	return c.transferFromContractEventRecordableHeight
}

// AcceptFuncAvailableHeight ..
func (c *CompatibilityMainNet) AcceptFuncAvailableHeight() uint64 {
	return c.acceptFuncAvailableHeight
}

// RandomAvailableHeight ..
func (c *CompatibilityMainNet) RandomAvailableHeight() uint64 {
	return c.randomAvailableHeight
}

// DateAvailableHeight ..
func (c *CompatibilityMainNet) DateAvailableHeight() uint64 {
	return c.dateAvailableHeight
}

// RecordCallContractResultHeight ..
func (c *CompatibilityMainNet) RecordCallContractResultHeight() uint64 {
	return c.recordCallContractResultHeight
}

// NvmMemoryLimitWithoutInjectHeight ..
func (c *CompatibilityMainNet) NvmMemoryLimitWithoutInjectHeight() uint64 {
	return c.nvmMemoryLimitWithoutInjectHeight
}

// WsResetRecordDependencyHeight ..
func (c *CompatibilityMainNet) WsResetRecordDependencyHeight() uint64 {
	return c.wsResetRecordDependencyHeight
}

// WsResetRecordDependencyHeight2 ..
func (c *CompatibilityMainNet) WsResetRecordDependencyHeight2() uint64 {
	return c.wsResetRecordDependencyHeight2
}

// V8JSLibVersionControlHeight ..
func (c *CompatibilityMainNet) V8JSLibVersionControlHeight() uint64 {
	return c.v8JSLibVersionControlHeight
}

// TransferFromContractFailureEventRecordableHeight ..
func (c *CompatibilityMainNet) TransferFromContractFailureEventRecordableHeight() uint64 {
	return c.transferFromContractFailureEventRecordableHeight
}

// TransferFromContractFailureEventRecordableHeight2 ..
func (c *CompatibilityMainNet) TransferFromContractFailureEventRecordableHeight2() uint64 {
	return c.transferFromContractFailureEventRecordableHeight2
}

// NewNvmExeTimeoutConsumeGasHeight ..
func (c *CompatibilityMainNet) NewNvmExeTimeoutConsumeGasHeight() uint64 {
	return c.newNvmExeTimeoutConsumeGasHeight
}

// V8JSLibVersionHeightMap ..
func (c *CompatibilityMainNet) V8JSLibVersionHeightMap() *V8JSLibVersionHeightMap {
	return c.v8JSLibVersionHeightMap
}

// NvmGasLimitWithoutTimeoutHeight ..
func (c *CompatibilityMainNet) NvmGasLimitWithoutTimeoutHeight() uint64 {
	return c.nvmGasLimitWithoutTimeoutHeight
}